package homework.ch11_13.p1;

/**
 * 生成报表任务
 */
public class GenerateReportTask implements Task {
    @Override
    public void execute() {
        System.out.println("[GenerateReportTask] report generated.");
    }
}

