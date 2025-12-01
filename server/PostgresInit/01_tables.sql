-- Users table
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Profiles table
CREATE TABLE profiles (
    id SERIAL PRIMARY KEY,
    user_id INT UNIQUE REFERENCES users(id) ON DELETE CASCADE,
    nickname VARCHAR(50),
    rank INT DEFAULT 0,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    image_path VARCHAR(255),
    achievements JSONB DEFAULT '{}'::JSONB

    -- Achievements example. Add new via Client Request and signature check.
    -- {
    --   "first_login": true,
    --   "high_score": 1500,
    --   "badges": ["beginner", "shooter"]
    --   +"new_achievement": /Value in any format./ -> game_service/internal/users_provider/system...
    -- }
);


