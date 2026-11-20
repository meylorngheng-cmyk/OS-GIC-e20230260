
class MyRunnable implements Runnable {
    private int threadNumber;

    MyRunnable(int number) {
        threadNumber = number;
    }

    public void run() {
        System.out.println("Runnable thread " + threadNumber + " is running.");

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted.");
        }

        System.out.println("Runnable thread " + threadNumber + " finished.");
    }
}

public class RunnableDemo {
    public static void main(String[] args) {
        Thread t1 = new Thread(new MyRunnable(1));
        Thread t2 = new Thread(new MyRunnable(2));
        Thread t3 = new Thread(new MyRunnable(3));

        t1.start();
        t2.start();
        t3.start();
    }
}
