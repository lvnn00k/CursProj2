#include "report.hpp"

namespace shift 
{

void BaseReport::Print(std::unique_ptr<std::unique_ptr<receipt::BaseReceipt>[]>& allReceipts, int array_size) const
{
    std::cout << GetName();
    int receiptCount = 0;
    int returnReceiptCount = 0;
    double receiptsSum = 0;
    double returnReceiptsSum = 0;
    for (int i = 0; i < array_size; i++) 
    {
        auto& item = allReceipts[i];
        if (item->GetTypeID())
        {
            receiptCount++;
            receiptsSum += item->GetSum();
        } 
        else
        {
            returnReceiptCount++;
            returnReceiptsSum += item->GetSum();
        } 
    }

    std::cout << "Приход в кассу:\t" << receiptsSum <<"\n";
    std::cout << "Чеков: " << receiptCount <<"\n";
    std::cout << "Возраты:\t" << returnReceiptsSum <<"\n";
    std::cout << "Чеков: " << returnReceiptCount <<"\n";
    std::cout << "ИТОГ:\t" << receiptsSum-returnReceiptsSum <<"\n";

}



}