package receipt;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Receipt implements AutoCloseable {
    private List<ReceiptItem> items = new ArrayList<>();
    private boolean isReceiptEmpty() 
    {
        if (items.isEmpty()) {
            System.out.println("Чек пуст");
            return true;
        }
        return false;
    }

    public void addNewItem()
    {
        int number, count;
        Scanner scanner = new Scanner(System.in);

        while(true) 
        {
            System.out.print("Укажите номер товара: ");
            number = scanner.nextInt();

            if (number > 0 && number <= Products.array.size()) {
                break;
            }
            System.out.println("Такого товара не существует.");
        }
        while(true)
        {
            System.out.print("Количество: ");
            count = scanner.nextInt();

            if (count > 0) {
                break;
            }
            System.out.println("Количесвто не может быть меньше 1.");
        }

        items.add(new ReceiptItem(Products.array.get(number-1), count));
    }

    public void deleteItem() 
    {
        if (isReceiptEmpty()) return;

        Scanner scanner = new Scanner(System.in);
        int number;
        while(true)
        {
            System.out.print("Введите номер который хотите удалить: ");
            number = scanner.nextInt();

            if (number > 0 && number <= items.size()) {
                break;
            }
            System.out.println("Позиции с таким номером нет.");
        }

        ReceiptItem item = items.remove(number-1);
        item.close();
        
    }

    public void showAll()
    {
        if (isReceiptEmpty()) return;

        for (ReceiptItem item : items) 
        {
            System.out.println(item);
            System.out.printf("НДС %f \n", item.getNds());
        }
    }

    

    @Override
    public void close() 
    {
        System.out.println("Чек удален");
    }

    public String toString()
    {
        return "Чек создан!";
    }

}