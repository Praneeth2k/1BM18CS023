
class A implements Runnable{
    Thread t;
	B ob2;
    A(){
	t=new Thread(this,"Thread 1");
        ob2=new B();
        t.start();
    }
    public void run(){
        
        try{
	ob2.t.join();}
	catch(InterruptedException e){}
        System.out.println("Hello from T1");
    }
}
class B implements Runnable{
    Thread t;
    C ob3;
    B(){
	t=new Thread(this,"Thread 2");
        ob3=new C();
        t.start();
    }
    public void run(){
        try{
	ob3.t.join();}
	catch(InterruptedException e){}
        System.out.println("Hello from T2");
    }
}
class C implements Runnable{
    Thread t;
     D ob4;
    C(){
	t=new Thread(this,"Thread 3");
        ob4=new D();
        t.start();
    }
    public void run(){
        try{
	ob4.t.join();}
	catch(InterruptedException e){}
        System.out.println("Hello from T3");
    }
}
class D implements Runnable{
    Thread t;
	E ob5;
    D(){
	t=new Thread(this,"Thread 4");
        ob5=new E();
        t.start();
    }
    public void run(){
	try{
	ob5.t.join();}
	catch(InterruptedException e){}
        System.out.println("Hello from T4");
    }
}
class E implements Runnable{
    Thread t;
    E(){
	t=new Thread(this,"Thread 5");
        t.start();
    }
    public void run(){
        System.out.println("Hello from T5");
    }
}
class callthreads{
    public static void main(String args[]){
        new A();
    }
}

	
