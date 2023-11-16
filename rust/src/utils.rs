use crate::particle::Particle;
use crate::vec2d::Vec2d;

pub fn f_rand(f_min: f64, f_max: f64) -> f64 {
    let f: f64 = rand::random();
    f_min + f * (f_max - f_min)
}

pub fn distance(lhs: &Particle, rhs: &Particle) -> f64 {
    (lhs.pos - rhs.pos).magnitude()
}

pub fn dist(lhs: Vec2d, rhs: Vec2d) -> f64 {
    (lhs - rhs).magnitude()
}