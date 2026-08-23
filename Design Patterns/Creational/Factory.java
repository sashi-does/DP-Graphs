interface Logistics {
    public void send();
}

class Airplane implements Logistics {
    public Airplane() {

    }
    @Override
    public void send() {
        System.out.println("Sending via airways..");
    }
}

class Train implements Logistics {
    public Train() {

    }
    @Override
    public void send() {
        System.out.println("Sending via train chuk chuk..");
    }
}

// single class is handling which object to create and invoke method
// if new method is added and again this has to be changed 
// class LogisticService {
//     public LogisticService() {
        
//     }

//     public void send(String mode) {
//         if(mode == "air") {
//             Logistics airplane = new Airplane();
//             airplane.send();
//         }
//         else if(mode == "train") {
//             Logistics train = new Train();
//             train.send();
//         }
//     }
// }

// so give creation work to other class
// """str.equals(str2) not == """
// easy to add other types of modes here
class LogisticFactory {
    public static Logistics getLogisticServiceType(String mode) {
        // could be enum either way deals with same
        if(mode == "train")
            return new Train();
        // else if(mode == "air")
        return new Airplane();
    }
}

// this will only call the method dont need to handle the logic part here
class LogisticService {
    public LogisticService() {
        
    }

    public void send(String mode) {
        // just get the respective object and directly call the method
        Logistics type = LogisticFactory.getLogisticServiceType(mode);
        type.send();
    }
}

public class Factory {
    public static void main(String args[]) {
        L
    } 
}