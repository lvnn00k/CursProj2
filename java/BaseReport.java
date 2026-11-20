package shift;

import java.util.ArrayList;
import java.util.List;
import receipt.*;

public abstract class BaseReport {

    public void print(List<BaseReceipt> allReceipts)
    {
        System.out.println(getName());
        int receiptCount = 0;
        int returnReceiptCount = 0;
        double receiptsSum = 0;
        double returnReceiptsSum = 0; 
        for (BaseReceipt receipt : allReceipts) 
        {
            if (receipt.getTypeID() == 1) 
            {
                receiptCount++;
                receiptsSum += receipt.getSum();
            }
            else 
            {
                returnReceiptCount++;
                returnReceiptsSum += receipt.getSum();
            }
        }

        System.out.printf("Приход в кассу:\t%f \n", receiptsSum);
        System.out.printf("Чеков: %d \n", receiptCount);
        System.out.printf("Возраты:\t%f \n", returnReceiptsSum);
        System.out.printf("Чеков: %d \n", returnReceiptCount);
        System.out.printf("ИТОГ:\t%f \n", receiptsSum-returnReceiptsSum);
    }

    protected abstract String getName();
}