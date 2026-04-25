package homework.ch11_13.p4;

/**
 * 编程第3题测试入口
 */
public class Test {
    public static void main(String[] args) {
        Component computer = ComponentFactory.create();
        System.out.println(computer);

        System.out.println("id: " + computer.getId() + ", name: " + computer.getName() + ", price:" + computer.getPrice());
        ComponentIterator it = computer.createIterator();
        while (it.hasNext()) {
            Component c = it.next();
            System.out.println("id: " + c.getId() + ", name: " + c.getName() + ", price:" + c.getPrice());
        }
    }
}

