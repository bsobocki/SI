#include <iostream>
#include <vector>

size_t numberOfSetBits(std::vector<bool>::iterator beg, std::vector<bool>::iterator end)
{
   size_t count = 0;

   while (beg != end) count += *beg++;

   return count;
}

int optDist(std::vector<bool> bitStr, size_t blockSize)
{
   const size_t numOfSetBitsInBitStr = numberOfSetBits(bitStr.begin(), bitStr.end());

   size_t dist = bitStr.size();
   auto start = bitStr.begin();
   auto end = start + blockSize;

   while (end <= bitStr.end())
   {
      const size_t numOfSetBitsInBlock = numberOfSetBits(start, end);
      const size_t numOfClearBitsInBlock = blockSize - numOfSetBitsInBlock;
      const size_t numOfSetBitsOutsideBlock = numOfSetBitsInBitStr - numOfSetBitsInBlock;
      const size_t tempDist = numOfClearBitsInBlock + numOfSetBitsOutsideBlock;

      dist = std::min<size_t>(dist, tempDist);

      start++;
      end++;
   }

   return dist;
}