
class MyThread extends Thread {
    private int threadNumber;

    MyThread(int number) {
        threadNumber = number;
    }

    public void run() {
        System.out.println("Thread " + threadNumber + " is running.");

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted.");
        }

        System.out.println("Thread " + threadNumber + " finished.");
    }
}

public class ThreadDemo {
    public static void main(String[] args) {
        MyThread t1 = new MyThread(1);
        MyThread t2 = new MyThread(2);
        MyThread t3 = new MyThread(3);

        t1.start();
        t2.start();
        t3.start();
    }
}
