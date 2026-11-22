package shift;

import java.util.Scanner;
import java.lang.ref.WeakReference;
import  receipt.*;

class Main {

    public enum ShiftActions {
        CreateReceipt, PrintReport, Back;
    }

    public enum Action {
        OpenShift, CloseShift, Exit;
    }

    private Shift shiftSwitch(Shift shift) {
        Scanner scanner = new Scanner(System.in);
        ShiftActions shiftActions;
        if (shift == null ) shift = new Shift();
        do {
            System.out.print("1. Создать новый чек\n2. X-отчет\n3. Вернуться к смене\nВыберите пункт: ");
            shiftActions = ShiftActions.values()[scanner.nextInt()-1];
            switch(shiftActions) {
                case CreateReceipt:
                    shift.createNewReceipt();
                    break;
                case PrintReport:
                    shift.printXReport();
                    break;
                case Back:
                    System.out.print("\n");
                    break;
            }
        } while (shiftActions != ShiftActions.Back);
        return shift;
    }

    public void main() {
        Action action = null;
        Shift shift = null;
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.print("1. Открыть/Продолжить смену\n2. Закрыть смену\n3. Выход\nВыберите пункт: ");
            try {
                action = Action.values()[scanner.nextInt()-1];
                switch(action) {
                    case OpenShift:
                        shift = shiftSwitch(shift);
                        break;
                    case CloseShift:
                        if (shift != null) { 
                            shift.close(); 
                            shift = null;
                        } else { 
                            System.out.println("Смена еще не открыта."); 
                        }
                        break;
                    case Exit:
                        System.out.println("Работа завершена.");
                        break;
                }

            } catch (Throwable _) {
                System.out.println("Такого пункта нет.");
            } 

        } while (action != Action.Exit);
    }
}
