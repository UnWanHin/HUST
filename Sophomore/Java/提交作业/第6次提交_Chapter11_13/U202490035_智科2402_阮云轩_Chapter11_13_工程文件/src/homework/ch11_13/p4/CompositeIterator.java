package homework.ch11_13.p4;

import java.util.ArrayList;
import java.util.List;

/**
 * 复合组件迭代器
 */
public class CompositeIterator implements ComponentIterator {
    /**
     * 保存待处理迭代器的列表
     */
    protected List<ComponentIterator> iterators;

    /**
     * 构造函数
     */
    public CompositeIterator(ComponentIterator iterator) {
        this.iterators = new ArrayList<>();
        if (iterator != null) {
            this.iterators.add(iterator);
        }
    }

    @Override
    public boolean hasNext() {
        while (!iterators.isEmpty()) {
            ComponentIterator current = iterators.get(0);
            if (current.hasNext()) {
                return true;
            }
            iterators.remove(0);
        }
        return false;
    }

    @Override
    public Component next() {
        if (!hasNext()) {
            return null;
        }
        ComponentIterator current = iterators.get(0);
        Component component = current.next();
        if (component != null) {
            ComponentIterator childIterator = component.createIterator();
            if (childIterator != null) {
                iterators.add(childIterator);
            }
        }
        return component;
    }
}

