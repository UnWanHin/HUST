package homework.ch11_13.p4;

/**
 * 原子组件
 */
public class AtomicComponent extends Component {
    /**
     * 缺省构造函数
     */
    public AtomicComponent() {
    }

    /**
     * 构造函数
     */
    public AtomicComponent(int id, String name, double price) {
        super(id, name, price);
    }

    @Override
    public void add(Component component) throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Atomic component can not add child component.");
    }

    @Override
    public void remove(Component component) throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Atomic component can not remove child component.");
    }

    @Override
    public double calcPrice() {
        return getPrice();
    }

    @Override
    public ComponentIterator createIterator() {
        return new NullIterator();
    }
}

