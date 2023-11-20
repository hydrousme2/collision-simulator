use std::sync::{Arc, Mutex};
use std::thread;

pub mod collision;
pub mod particle;
pub mod vec2d;
pub mod config;
pub mod utils;

use collision::{detect_collision, border_collision};
use particle::{Particle};
use vec2d::Vec2d;
use utils::{f_rand};
use config::*;


fn gridify(particles: &[Particle], threshold: &Vec2d, subgrids: &mut [Vec<Particle>]) {
    for particle in particles {
        let x = (particle.pos.x / threshold.x) as usize;
        let y = (particle.pos.y / threshold.y) as usize;

        let x = x.clamp(0, N_G - 1);
        let y = y.clamp(0, N_G - 1);

        let idx = x * N_G + y;

        subgrids[idx].push(particle.clone());
    }
}

fn main() {
    let mut particles = Vec::new();

    for i in 0..N {
        let idx = i as i32;

        let radius = f_rand(R_MIN, R_MAX);

        let pos = Vec2d::with_values(
            f_rand(radius, X_SIZE - radius),
            f_rand(radius, Y_SIZE - radius),
        );

        let vel = Vec2d::with_values(
            f_rand(V_MIN, V_MAX),
            f_rand(V_MIN, V_MAX),
        );

        let particle = Particle::new(pos, vel, radius, idx);
        particles.push(particle);
    }

    println!("T = 0");
    for (i, particle) in particles.iter().enumerate() {
        println!(
            "[{}] ({}, {}) ({}, {}) {}",
            i,
            particle.pos.x,
            particle.pos.y,
            particle.vel.x,
            particle.vel.y,
            particle.radius
        );
    }

    let threshold = Vec2d::with_values(X_SIZE / N_G as f64, Y_SIZE / N_G as f64);

    let mut t = 0.0;

    while t < TF {
        for particle in particles.iter_mut() {
            particle.update();
            border_collision(particle);

        }

        let mut subgrids: Vec<Vec<Particle>> = (0..N_T)
            .map(|_| Vec::new())
            .collect();

        gridify(&particles, &threshold, &mut subgrids);

        let mut threads = Vec::new();
        for i in 0..N_T {
            let subgrid_clone = Arc::new(Mutex::new(subgrids[i].clone()));
            threads.push(thread::spawn(move || {
                detect_collision(&mut subgrid_clone.lock().unwrap());
            }));
        }

        for thread in threads {
            thread.join().unwrap();
        }

        t += DT;
    }

    println!("T = {}", TF);
    for (i, particle) in particles.iter().enumerate() {
        println!(
            "[{}] ({}, {}) ({}, {}) {}",
            i,
            particle.pos.x,
            particle.pos.y,
            particle.vel.x,
            particle.vel.y,
            particle.radius
        );
    }
}
