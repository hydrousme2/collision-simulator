#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Vec2d {
    pub x: f64,
    pub y: f64,
}

impl Vec2d {
    pub fn new() -> Self {
        Vec2d { x: 0.0, y: 0.0 }
    }

    pub fn with_values(x: f64, y: f64) -> Self {
        Vec2d { x, y }
    }

    pub fn magnitude(&self) -> f64 {
        (self.x * self.x + self.y * self.y).sqrt()
    }

    pub fn normalize(&mut self) {
        let m = self.magnitude();
        self.x /= m;
        self.y /= m;
    }
    pub fn dot(&self, other: &Vec2d) -> f64 {
        self.x * other.x + self.y * other.y
    }
}

impl std::ops::Add for Vec2d {
    type Output = Self;

    fn add(self, rhs: Self) -> Self {
        Vec2d {
            x: self.x + rhs.x,
            y: self.y + rhs.y,
        }
    }
}

impl std::ops::Sub for Vec2d {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self {
        Vec2d {
            x: self.x - rhs.x,
            y: self.y - rhs.y,
        }
    }
}

impl std::ops::Mul<f64> for Vec2d {
    type Output = Self;

    fn mul(self, rhs: f64) -> Self {
        Vec2d {
            x: self.x * rhs,
            y: self.y * rhs,
        }
    }
}

impl std::ops::Div<f64> for Vec2d {
    type Output = Self;

    fn div(self, rhs: f64) -> Self {
        Vec2d {
            x: self.x / rhs,
            y: self.y / rhs,
        }
    }
}
