package homework.ch11_13.p4;

/**
 * 复合组件
 */
public class CompositeComponent extends Component {
    /**
     * 子组件列表
     */
    protected ComponentList children;

    /**
     * 缺省构造函数
     */
    public CompositeComponent() {
        this.children = new ComponentList();
    }

    /**
     * 构造函数
     */
    public CompositeComponent(int id, String name, double price) {
        super(id, name, price);
        this.children = new ComponentList();
    }

    @Override
    public void add(Component component) throws UnsupportedOperationException {
        if (component != null) {
            children.add(component);
            setPrice(calcPrice());
        }
    }

    @Override
    public void remove(Component component) throws UnsupportedOperationException {
        children.remove(component);
        setPrice(calcPrice());
    }

    @Override
    public double calcPrice() {
        double sum = 0.0;
        for (Component child : children) {
            sum += child.calcPrice();
        }
        setPrice(sum);
        return sum;
    }

    @Override
    public ComponentIterator createIterator() {
        return new CompositeIterator(children.createIterator());
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        sb.append(", children=[");
        for (int i = 0; i < children.size(); i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(children.get(i));
        }
        sb.append("]");
        return sb.toString();
    }
}

