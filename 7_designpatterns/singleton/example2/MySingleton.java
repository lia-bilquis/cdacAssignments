import java.lang.reflect.Constructor;

/*
public class MySingleton {

}*/

public class MySingleton {
    private static final MySingleton instance = new MySingleton();

    private MySingleton() {}

    public static MySingleton getInstance() {
        return instance;
    }
}

 class SingletonAndReflection {
    public static void main(String[] args) {
        MySingleton singletonInstance = MySingleton.getInstance();
        MySingleton reflectionInstance = null;
        
        try {
            Constructor[] constructors = MySingleton.class.getDeclaredConstructors();
            for (Constructor constructor : constructors) {
                constructor.setAccessible(true);
                reflectionInstance = (MySingleton) constructor.newInstance();
            }
        } catch (Exception ex) {
            throw new RuntimeException(ex);
        }

        System.out.println("singletonInstance hashCode: " + singletonInstance.hashCode());
        System.out.println("reflectionInstance hashCode: " + reflectionInstance.hashCode());
    }
}
