// used when there are more optional parameters which can be 
// handled with constructor overloading but requires to write 
// all the combinations of parameters

// builder pattern effectively solves this with using static inner class

class User {

    private final String name;
    private final int age;

    // optional
    private final String email;
    private final String phone;

    public User(UserBuilder user) {
        this.name = user.name;
        this.age = user.age;
        this.email = user.email;
        this.phone = user.phone;
    }

    public static class UserBuilder {
        private final String name;
        private final int age;
        private final String email;
        private final String phone; 

        public UserBuilder setName(String name) {
            this.name = name;
            return this;
        }

        public UserBuilder setAge(int age) {
            this.age = age;
            return this;
        }

        public UserBuilder setEmail(String email) {
            this.email = email;
            return this;
        }

        public UserBuilder setPhone(String phone) {
            this.phone = phone;
            return this;
        }

        public User build() {
            return new User(this);
        }

    }

};

public class Builder {
    public static void main(String args[]) {
        User user = new User.UserBuilder()
                            .setName("sashi")
                            .setAge(20)
                            .setEmail("work.with.sashi.dev@gmail.com")
                            .build();
    }
}