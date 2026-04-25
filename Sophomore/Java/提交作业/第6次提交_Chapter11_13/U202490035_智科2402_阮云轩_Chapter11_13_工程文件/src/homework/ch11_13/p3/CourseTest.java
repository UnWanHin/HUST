package homework.ch11_13.p3;

/**
 * 编程第2题测试入口
 */
public class CourseTest {
    public static void main(String[] args) throws CloneNotSupportedException {
        Faculty teacher = new Faculty("James Gosling", 65, 1, "Professor", "jag@example.com");
        Course java = new Course("Java Language Programming", teacher);

        Student s1 = new Student("aaa", 20, 20170101, "CS", "CS1704");
        Student s2 = new Student("bbb", 20, 20170102, "CS", "CS1705");
        Student s3 = new Student("ccc", 20, 20170103, "CS", "CS1706");

        java.register(s1);
        java.register(s2);
        java.register(s3);

        Course cpp = new Course("C++ Language Programming",
                new Faculty("T1", 40, 2, "Professor", "t1@example.com"));
        cpp.register((Person) s1.clone());
        cpp.register((Person) s2.clone());
        cpp.register((Person) s3.clone());

        Course[] courses = {java, cpp};
        for (Course c : courses) {
            System.out.println(c);
        }

        Course cloned = (Course) java.clone();
        System.out.println("java.equals(cloned) = " + java.equals(cloned));
        System.out.println("java == cloned = " + (java == cloned));
        System.out.println("java.getTeacher() == cloned.getTeacher() = " + (java.getTeacher() == cloned.getTeacher()));
        System.out.println("java.getStudents() == cloned.getStudents() = " + (java.getStudents() == cloned.getStudents()));
    }
}

