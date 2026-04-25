package homework.ch11_13.p3;

import java.util.Objects;

/**
 * 父类
 */
public class Person implements Cloneable {
    /**
     * 姓名
     */
    private String name;

    /**
     * 年龄
     */
    private int age;

    /**
     * 缺省构造函数
     */
    public Person() {
    }

    /**
     * 构造函数
     *
     * @param name 姓名
     * @param age  年龄
     */
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    /**
     * 获取姓名
     *
     * @return 姓名
     */
    public String getName() {
        return name;
    }

    /**
     * 设置姓名
     *
     * @param name 姓名
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * 获取年龄
     *
     * @return 年龄
     */
    public int getAge() {
        return age;
    }

    /**
     * 设置年龄
     *
     * @param age 年龄
     */
    public void setAge(int age) {
        this.age = age;
    }

    /**
     * 覆盖 toString
     *
     * @return 描述信息
     */
    @Override
    public String toString() {
        return "Person{name='" + name + "', age=" + age + "}";
    }

    /**
     * 比较二个 Person 对象的内容是否相等
     *
     * @param obj 比较对象
     * @return true/false
     */
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Person person = (Person) obj;
        return age == person.age && Objects.equals(name, person.name);
    }

    /**
     * Person 的深拷贝克隆
     *
     * @return 克隆对象
     * @throws CloneNotSupportedException Cloneable 相关异常
     */
    @Override
    public Object clone() throws CloneNotSupportedException {
        Person newObj = (Person) super.clone();
        newObj.name = this.name == null ? null : new String(this.name);
        return newObj;
    }
}

