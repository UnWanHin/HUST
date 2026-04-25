package homework.ch11_13.p1;

/**
 * 编程第1题测试入口
 */
public class TaskDemo {
    public static void main(String[] args) {
        TaskService service = new TaskServiceImpl();
        service.addTask(new PrintDateTask());
        service.addTask(new DataBackupTask());
        service.addTask(new GenerateReportTask());
        service.exeuteTasks();
    }
}

