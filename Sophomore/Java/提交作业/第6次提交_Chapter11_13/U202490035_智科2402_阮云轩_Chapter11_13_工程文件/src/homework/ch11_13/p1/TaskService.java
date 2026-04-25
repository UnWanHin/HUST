package homework.ch11_13.p1;

/**
 * 任务服务接口
 */
public interface TaskService {
    /**
     * 执行任务列表中的每个任务
     */
    void exeuteTasks();

    /**
     * 添加任务
     *
     * @param t 新任务
     */
    void addTask(Task t);
}

