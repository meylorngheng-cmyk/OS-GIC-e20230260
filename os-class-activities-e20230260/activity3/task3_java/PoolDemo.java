
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class PoolDemo {
    public static void main(String[] args) {

        // Create a pool with 2 worker threads
        ExecutorService executor = Executors.newFixedThreadPool(2);

        // Submit 5 tasks
        for (int i = 1; i <= 5; i++) {
            final int taskNumber = i;

            executor.submit(() -> {
                System.out.println(
                    "Task " + taskNumber +
                    " is running on " +
                    Thread.currentThread().getName()
                );
            });
        }

        // Shut down the executor
        executor.shutdown();

        System.out.println("All tasks submitted.");
    }
}
