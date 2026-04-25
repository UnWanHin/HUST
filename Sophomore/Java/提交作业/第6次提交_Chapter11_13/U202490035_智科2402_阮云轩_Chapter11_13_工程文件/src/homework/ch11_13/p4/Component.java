package homework.ch11_13.p4;

import java.util.Objects;

/**
 * 抽象组件
 */
public abstract class Component {
    /**
     * 组件 id
     */
    protected int id;

    /**
     * 组件名字
     */
    protected String name;

    /**
     * 组件价格
     */
    protected double price;

    /**
     * 缺省构造函数
     */
    public Component() {
    }

    /**
     * 构造函数
     */
    public Component(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public abstract void add(Component component) throws UnsupportedOperationException;

    public abstract void remove(Component component) throws UnsupportedOperationException;

    public abstract double calcPrice();

    public abstract ComponentIterator createIterator();

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Component that = (Component) obj;
        return id == that.id
                && Double.compare(that.price, price) == 0
                && Objects.equals(name, that.name);
    }

    @Override
    public String toString() {
        return "id: " + id + ", name: " + name + ", price:" + price;
    }
}

