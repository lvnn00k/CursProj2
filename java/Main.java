package receipt;

import java.util.Scanner;
import java.lang.ref.WeakReference;

class Main {

    public enum ItemAction {
        NewItem, DeleteItem, Show, BackToReceipt, LinksAndCopies;
    }

    public enum ReceiptAction {
        NewReceipt, DeleteReceipt, Exit, WeakRef, FreeResources;
    }

    private Receipt newReceiptSwitch(Receipt receipt) {
        Scanner scanner = new Scanner(System.in);
        ItemAction itemAction;
        if (receipt == null ) receipt = new Receipt();
        do {
            System.out.print("1. Добавить позицию чека\n2. Удалить позицию чека\n3. Вывести все\n4. Вернуться к чекам\n5. Ссылки и копии \nВыберите пункт: ");
            itemAction = ItemAction.values()[scanner.nextInt()-1];
            switch(itemAction) {
                case NewItem:
                    receipt.addNewItem();
                    break;
                case DeleteItem:
                    receipt.deleteItem();
                    break;
                case Show:
                    receipt.showAll();
                    break;
                case BackToReceipt:
                    System.out.print("\n");
                    break;
                case LinksAndCopies:
                    ReceiptItem receiptItem1 = new ReceiptItem(Products.array.get(0), 1);
                    System.out.println("Объект 1 (до изменения объекта 2): \n" + receiptItem1);
                    ReceiptItem receiptItem2 = receiptItem1;
                    System.out.println("Новые данные объекта 2: ");
                    int newData = scanner.nextInt();
                    receiptItem2.newAmount(newData);
                    System.out.println("Объект 1 (после изменения объекта 2): \n" + receiptItem1);
                    break;
            }
        } while (itemAction != ItemAction.BackToReceipt);
        return receipt;
    }

    public void main() {
        ReceiptAction receiptAction = null;
        Receipt receipt = null;
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.print("1. Создать чек\n2. Удалить чек\n3. Выход\n4. Слабая ссылка \n5. Освобождение ресурсов \nВыберите пункт: ");
            try {
                receiptAction = ReceiptAction.values()[scanner.nextInt()-1];
                switch(receiptAction) {
                    case NewReceipt:
                        receipt = newReceiptSwitch(receipt);
                        break;
                    case DeleteReceipt:
                        if (receipt != null) { 
                            receipt.close(); 
                            receipt = null;
                        } else { 
                            System.out.println("Чек еще не создан."); 
                        }
                        break;
                    case Exit:
                        System.out.println("Работа завершена.");
                        break;
                    case WeakRef:
                        Receipt temp = new Receipt();
                        WeakReference<Receipt> watcher = new WeakReference<>(temp);
                        System.out.println(watcher.get() != null);
                        temp = null;
                        System.out.println(watcher.get() != null); 
                        System.out.println("Блок закончен. Начинается сборка мусора");
                        System.gc();
                        System.out.println(watcher.get() != null);
                        System.out.println("Сборка мусора завершена");
                        break;
                    case FreeResources:
                        try (Receipt rec = new Receipt()) {
                            System.out.println(rec);
                            System.out.println("Выход из блока");
                        }
                        System.out.println("Блок закончен");
                        break;
                }

            } catch (Throwable _) {
                System.out.println("Такого пункта нет.");
            } 

        } while (receiptAction != ReceiptAction.Exit);
    }
}
