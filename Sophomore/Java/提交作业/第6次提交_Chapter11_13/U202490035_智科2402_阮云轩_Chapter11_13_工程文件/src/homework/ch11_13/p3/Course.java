package homework.ch11_13.p3;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 * 课程类
 */
public class Course implements Cloneable {
    /**
     * 课程名称
     */
    private String courseName;

    /**
     * 学生列表
     */
    private List<Person> students;

    /**
     * 授课教师
     */
    private Person teacher;

    /**
     * 构造函数
     *
     * @param courseName 课程名称
     * @param teacher    教师
     */
    public Course(String courseName, Person teacher) {
        this.courseName = courseName;
        this.teacher = teacher;
        this.students = new ArrayList<>();
    }

    /**
     * 注册学生，避免重复注册
     */
    public void register(Person s) {
        if (s != null && !students.contains(s)) {
            students.add(s);
        }
    }

    /**
     * 获取课程名
     */
    public String getCourseName() {
        return courseName;
    }

    /**
     * 获取学生列表
     */
    public List<Person> getStudents() {
        return students;
    }

    /**
     * 获取教师
     */
    public Person getTeacher() {
        return teacher;
    }

    /**
     * 取消注册
     */
    public void unregister(Person s) {
        students.remove(s);
    }

    /**
     * 学生人数
     */
    public int getNumberOfStudent() {
        return students.size();
    }

    /**
     * 深拷贝克隆
     */
    @Override
    public Object clone() throws CloneNotSupportedException {
        Course newObj = (Course) super.clone();
        newObj.courseName = this.courseName == null ? null : new String(this.courseName);
        newObj.teacher = this.teacher == null ? null : (Person) this.teacher.clone();
        newObj.students = new ArrayList<>();
        for (Person p : this.students) {
            newObj.students.add(p == null ? null : (Person) p.clone());
        }
        return newObj;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Course{courseName='").append(courseName).append("', teacher=");
        sb.append(teacher);
        sb.append(", students=[");
        for (int i = 0; i < students.size(); i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(students.get(i));
        }
        sb.append("]}");
        return sb.toString();
    }

    /**
     * 比较内容是否一致（学生列表忽略顺序）
     */
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof Course)) {
            return false;
        }
        Course course = (Course) obj;
        if (!Objects.equals(courseName, course.courseName)) {
            return false;
        }
        if (!Objects.equals(teacher, course.teacher)) {
            return false;
        }
        if (students == null && course.students == null) {
            return true;
        }
        if (students == null || course.students == null) {
            return false;
        }
        return students.size() == course.students.size()
                && students.containsAll(course.students)
                && course.students.containsAll(students);
    }
}

