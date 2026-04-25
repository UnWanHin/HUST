package homework.ch11_13.p1;

/**
 * 数据备份任务
 */
public class DataBackupTask implements Task {
    @Override
    public void execute() {
        System.out.println("[DataBackupTask] backup finished.");
    }
}

