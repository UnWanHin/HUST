package homework.ch11_13.p4;

import java.util.ArrayList;

/**
 * 组件列表
 */
public class ComponentList extends ArrayList<Component> implements ComponentIterator {
    /**
     * 当前迭代位置
     */
    private int position;

    /**
     * 缺省构造函数
     */
    public ComponentList() {
        this.position = 0;
    }

    @Override
    public boolean hasNext() {
        return position < this.size();
    }

    @Override
    public Component next() {
        if (hasNext()) {
            return this.get(position++);
        }
        return null;
    }

    /**
     * 重置并返回迭代器
     */
    public ComponentIterator createIterator() {
        this.position = 0;
        return this;
    }
}

