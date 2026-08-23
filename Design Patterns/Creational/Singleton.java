// two ways of creating singleton class
 
// 1. while loading of class (eager loading)
// this is thread-safe
class DBConnectionEager {
    private static conn = new DBConnectionEager();
    private DBConnectionEager() {
        
    }
    public static DBConnectionEager getConn() {
        return conn;
    }
};

// 2. after loading of class (lazy loading)
// not thread safe
class DBConnectionLazy {
    private static conn;
    private DBConnectionLazy() {
        
    }
    public static DBConnectionLazy getConn() {
        if(conn == null)
            return new DBConnectionLazy();
        return conn;
    }
};

public class Singleton {
    public static void main(String args[]) {
        DBConnectionLazy dbl;
        DBConnectionEager dbe;
    }
}