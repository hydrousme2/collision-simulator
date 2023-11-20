use crate::particle::{Particle};
use crate::config::{X_SIZE, Y_SIZE};

pub fn check_collision(a: &Particle, b: &Particle) -> bool {
    let s = a.pos - b.pos;
    let v = a.vel - b.vel;
    let r = a.radius + b.radius;

    let c1 = s.dot(&s) - r * r;
    if c1 < 0.0 {
        return true;
    }

    let a1 = v.dot(&v);
    if a1 < 0.00001 {
        return false;
    }

    let b1 = v.dot(&s);
    if b1 >= 0.0 {
        return false;
    }

    let d1 = b1 * b1 - a1 * c1;
    d1 >= 0.0
}

pub fn border_collision(particle: &mut Particle) {
    if particle.pos.x < 0.0 {
        particle.pos.x = 0.0;
        particle.vel.x *= -1.0;
    }
    if particle.pos.x > X_SIZE as f64 {
        particle.pos.x = X_SIZE as f64;
        particle.vel.x *= -1.0;
    }
    if particle.pos.y < 0.0 {
        particle.pos.y = 0.0;
        particle.vel.y *= -1.0;
    }
    if particle.pos.y > Y_SIZE as f64 {
        particle.pos.y = Y_SIZE as f64;
        particle.vel.y *= -1.0;
    }
}

pub fn resolve_collision(a: &mut Particle, b: &mut Particle) {
    let x = a.pos - b.pos;
    let mut x_normalized = x;
    x_normalized.normalize();

    let v1 = a.vel;
    let v2 = b.vel;

    let x1 = x_normalized.dot(&v1);
    let x2 = x_normalized.dot(&v2);

    let m1 = a.radius;
    let m2 = b.radius;

    let optimized_p = (2.0 * (x1 - x2)) / (m1 + m2);

    a.vel = v1 - x_normalized * optimized_p * m2;
    b.vel = v2 + x_normalized * optimized_p * m1;
}

pub fn detect_collision(particles: &mut Vec<Particle>) {
    let n_c = particles.len();
    for i in 0..n_c {
        for j in (i + 1)..n_c {
            if check_collision(&particles[i], &particles[j]) {
                let mut particle_i_clone = particles[i].clone();
                let mut particle_j_clone = particles[j].clone();
                resolve_collision(&mut particle_i_clone, &mut particle_j_clone);
                particles[i] = particle_i_clone;
                particles[j] = particle_j_clone;
            }
        }
    }
}
