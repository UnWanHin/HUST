package homework.ch11_13.p3;

import java.util.Objects;

/**
 * 学生类
 */
public class Student extends Person {
    /**
     * 学号
     */
    private int studentId;

    /**
     * 系别
     */
    private String department;

    /**
     * 班级号
     */
    private String classNo;

    /**
     * 缺省构造函数
     */
    public Student() {
    }

    /**
     * 构造函数
     */
    public Student(String name, int age, int studentId, String department, String classNo) {
        super(name, age);
        this.studentId = studentId;
        this.department = department;
        this.classNo = classNo;
    }

    /**
     * 获取学号
     */
    public int getStudentId() {
        return studentId;
    }

    /**
     * 设置学号
     */
    public void setStudentId(int studentId) {
        this.studentId = studentId;
    }

    /**
     * 获取系别
     */
    public String getDepartment() {
        return department;
    }

    /**
     * 设置系别
     */
    public void setDepartment(String department) {
        this.department = department;
    }

    /**
     * 获取班级号
     */
    public String getClassNo() {
        return classNo;
    }

    /**
     * 设置班级号
     */
    public void setClassNo(String classNo) {
        this.classNo = classNo;
    }

    @Override
    public String toString() {
        return "Student{" + super.toString()
                + ", studentId=" + studentId
                + ", department='" + department + "'"
                + ", classNo='" + classNo + "'}";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof Student)) {
            return false;
        }
        if (!super.equals(obj)) {
            return false;
        }
        Student student = (Student) obj;
        return studentId == student.studentId
                && Objects.equals(department, student.department)
                && Objects.equals(classNo, student.classNo);
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        Student newObj = (Student) super.clone();
        newObj.department = this.department == null ? null : new String(this.department);
        newObj.classNo = this.classNo == null ? null : new String(this.classNo);
        return newObj;
    }
}

