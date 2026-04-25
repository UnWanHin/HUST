package homework.ch11_13.p3;

import java.util.Objects;

/**
 * 教师类
 */
public class Faculty extends Person {
    /**
     * 工号
     */
    private int facultyId;

    /**
     * 职称
     */
    private String title;

    /**
     * 邮箱
     */
    private String email;

    /**
     * 缺省构造函数
     */
    public Faculty() {
    }

    /**
     * 构造函数
     */
    public Faculty(String name, int age, int facultyId, String title, String email) {
        super(name, age);
        this.facultyId = facultyId;
        this.title = title;
        this.email = email;
    }

    /**
     * 获取工号
     */
    public int getFacultyId() {
        return facultyId;
    }

    /**
     * 设置工号
     */
    public void setFacultyId(int facultyId) {
        this.facultyId = facultyId;
    }

    /**
     * 获取职称
     */
    public String getTitle() {
        return title;
    }

    /**
     * 设置职称
     */
    public void setTitle(String title) {
        this.title = title;
    }

    /**
     * 获取邮箱
     */
    public String getEmail() {
        return email;
    }

    /**
     * 设置邮箱
     */
    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "Faculty{" + super.toString()
                + ", facultyId=" + facultyId
                + ", title='" + title + "'"
                + ", email='" + email + "'}";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof Faculty)) {
            return false;
        }
        if (!super.equals(obj)) {
            return false;
        }
        Faculty faculty = (Faculty) obj;
        return facultyId == faculty.facultyId
                && Objects.equals(title, faculty.title)
                && Objects.equals(email, faculty.email);
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        Faculty newObj = (Faculty) super.clone();
        newObj.title = this.title == null ? null : new String(this.title);
        newObj.email = this.email == null ? null : new String(this.email);
        return newObj;
    }
}

