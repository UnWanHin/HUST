package homework.ch11_13.p1;

import java.time.LocalDateTime;

/**
 * 打印当前时间的任务
 */
public class PrintDateTask implements Task {
    @Override
    public void execute() {
        System.out.println("[PrintDateTask] now = " + LocalDateTime.now());
    }
}

