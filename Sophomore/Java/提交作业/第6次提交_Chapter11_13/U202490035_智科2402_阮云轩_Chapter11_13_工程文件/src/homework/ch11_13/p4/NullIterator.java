package homework.ch11_13.p4;

/**
 * 原子组件的空迭代器
 */
public class NullIterator implements ComponentIterator {
    /**
     * 缺省构造函数
     */
    public NullIterator() {
    }

    @Override
    public boolean hasNext() {
        return false;
    }

    @Override
    public Component next() {
        return null;
    }
}

