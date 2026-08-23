// two ways of creating singleton class
 
// 1. while loading of class (eager loading)
// this is thread-safe
class DBConnectionEager {
    private static final DBConnectionEager conn = new DBConnectionEager();
    private DBConnectionEager() {
        
    }
    public static DBConnectionEager getConn() {
        return conn;
    }
};

// 2. after loading of class (lazy loading)
// not thread safe
// use synchronised to make it thread-safe but it is not efficient
class DBConnectionLazy {
    private static DBConnectionLazy conn;
    private DBConnectionLazy() {
        
    }
    // use synchronised for basic inefficient thread-safety
    public static DBConnectionLazy getConn() {
        if(conn == null)
            return new DBConnectionLazy();
        return conn;
    }
};

// thread-safe version (double-checking)
class DBConnectionLazy {
    private static volatile DBConnectionLazy  conn;
    private DBConnectionLazy() {
        
    }
    public static DBConnectionLazy getConn() {
        if(conn == null) {
            synchronised(DBConnectionLazy.class) {
                // make sure if any other thread has created
                if(conn == null) {
                    return conn = new DBConnectionLazy();
                }
            }
        }
        return conn;
    }
};

// bill pugh singleton (best practice for lazy loading)
class DBConnectionLazy {
    private DBConnectionLazy() {
        
    }
    private static class Holder {
        private static final DBConnectionLazy = new DBConnectionLazy();
    }
    public static DBConnectionLazy getConn() {
        return Holder.DBConnectionLazy;
    }
};


public class Singleton {
    public static void main(String args[]) {
        DBConnectionLazy dbl;
        DBConnectionEager dbe;
    }
}

