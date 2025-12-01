-- Create Profile on User creation
CREATE OR REPLACE FUNCTION create_profile_after_user()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO profiles(user_id, nickname)
    VALUES (NEW.id, NEW.username);
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_create_profile
AFTER INSERT ON users
FOR EACH ROW
EXECUTE FUNCTION create_profile_after_user();

-- Remove User on Profile deletion
CREATE OR REPLACE FUNCTION delete_user_after_profile()
RETURNS TRIGGER AS $$
BEGIN
    DELETE FROM users WHERE id = OLD.user_id;
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_delete_user
AFTER DELETE ON profiles
FOR EACH ROW
EXECUTE FUNCTION delete_user_after_profile();