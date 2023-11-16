use crate::vec2d::Vec2d; // Assuming vec2d module is in the same crate
use crate::config::DT;

#[derive(Debug, PartialEq, Clone)]
pub struct Particle {
    pub pos: Vec2d,
    pub vel: Vec2d,
    pub radius: f64,
    pub idx: i32,
}

impl Particle {
    pub fn new(pos: Vec2d, vel: Vec2d, radius: f64, idx: i32) -> Self {
        Particle { pos, vel, radius, idx }
    }

    pub fn custom_clone(&self) -> Self {
        Particle {
            pos: self.pos,
            vel: self.vel,
            radius: self.radius,
            idx: self.idx,
        }
    }

    pub fn set_vel(&mut self, vel: Vec2d) {
        self.vel = vel;
    }

    pub fn set_pos(&mut self, pos: Vec2d) {
        self.pos = pos;
    }

    pub fn update(&mut self) {
        self.pos = self.pos + self.vel * DT;
    }
}