package shift;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import receipt.*;

class Shift implements AutoCloseable {

    public enum ReceiptAction {
        AddItem, DeleteItem, Show, Back;
    }

    private List<BaseReceipt> receipts = new ArrayList<>();

    public void createNewReceipt()
    {
        int input;
        BaseReceipt newReceipt;
        System.out.print("1. Чек прихода\n2. Чек возврата\n3. Вернуться назад\nВведите тип создаваемого чека: ");
        Scanner scanner = new Scanner(System.in);
        input = scanner.nextInt();
        switch(input)
        {
            case 1:
                Receipt receipt = new Receipt();
                newReceiptActions(receipt);
                newReceipt = receipt;
                break;
            case 2:
                double returnSum;
                System.out.print("Введите сумму возврата: ");
                returnSum = scanner.nextDouble();
                ReturnReceipt returnReceipt = new ReturnReceipt(returnSum);
                newReceipt = returnReceipt;
                break;
            default:
                return;
        }
        receipts.add(newReceipt);
    }

    private void newReceiptActions(Receipt receipt)
    {
        int input;
        ReceiptAction receiptAction;
        do {
            System.out.print("1. Добавить позицию чека\n2. Удалить позицию чека\n3. Вывести все\n4. Закончить работу с чеком\nВыберите пункт: ");
            Scanner scanner = new Scanner(System.in);
            receiptAction = ReceiptAction.values()[scanner.nextInt()-1];
            switch(receiptAction) {
                case AddItem:
                    receipt.addNewItem();
                    break;
                case DeleteItem:
                    receipt.deleteItem();
                    break;
                case Show:
                    receipt.show();
                    break;
                case Back:
                    System.out.print("\n");
                    break;
            }
        } while (receiptAction != ReceiptAction.Back);
    }

    public void printXReport()
    {
        X_Report report = new X_Report();
        report.print(receipts);
    }

    @Override
    public void close() 
    {
        Z_Report z_Report = new Z_Report();
        z_Report.print(receipts);
        X_Report.resetCount();
        System.out.println("\nСмена закрыта\n");
    }

}