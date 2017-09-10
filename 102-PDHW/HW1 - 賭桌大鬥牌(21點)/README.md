# 賭桌大鬥牌(21點)

## 說明文件

### Class 設計與分析

Class Hacker 中有
 * Hacker(int M) 
  * 建構子，M為牌塔內有幾副牌
 * Estimate(int n, EricShuffler &sh, int deckn) 
  * 利用發牌器洗 n 次將結果存到 Prob[X][Y]
 * showNextCardProb(int face) 
  * 根據輸入牌面印出下一張各點的機率
 * PrintProbs() 
  * 印出前一張為 1~13 點時候一張為 1~13 點的機率
 * getBustingProb(int facesum, int face)
  * 根據傳入現在牌數總和與牌數印出爆牌機率

Class EricShuffler 中有
 * EricShuffler()
  * 建構子，讀入各牌面預設機率
 * shuffleCard(PokerCard &pc)
  * 將機率傳入洗牌器完成洗牌動作，洗牌透過隨機亂數產出 0~1 之間的值，再根據傳入的機率分布陣列選擇牌面，若要選擇牌面沒牌時，找向後的牌 
 * PrintProbs()
  * 作用為印出讀入的機率值
 * PrintProbSum()
  * 作用為印出讀入機率往上累加

 ### 架構圖

 ![UML](http://i.imgur.com/YEfUujv.png) 

 ### 程式執行

 透過
 /* 第一階段模擬：根據輸入的牌組數模擬發牌並記錄 */
 /* 第二階段模擬：設定賭金 */
 /* 第三階段模擬：設定玩家跟賭注 */
 /* 第四階段模擬：根據玩家數量+莊家 完成發牌動作 */
 /* 第五階段模擬：玩家與莊家輪迴 */
 /* 第六階段模擬：結算並詢問是否另啟新局 */
 /* 第七階段模擬：結束 */

 ### 使用說明

 開啟 CodeBlocks 並開啟專案檔 `.cbp` 編譯再執行