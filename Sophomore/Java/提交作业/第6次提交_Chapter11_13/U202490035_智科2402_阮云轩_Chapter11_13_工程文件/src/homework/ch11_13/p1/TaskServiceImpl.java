package homework.ch11_13.p1;

import java.util.ArrayList;
import java.util.List;

/**
 * TaskService 的实现
 */
public class TaskServiceImpl implements TaskService {
    private final List<Task> tasks = new ArrayList<>();

    @Override
    public void exeuteTasks() {
        for (Task task : tasks) {
            task.execute();
        }
    }

    @Override
    public void addTask(Task t) {
        if (t != null) {
            tasks.add(t);
        }
    }
}

