# Scytale cipher 
## các bước làm 
### mã hóa
1. get rid of the space (xóa dấu cách)
2. make everything caps (viết in hoa)
3. split it into a rows (chia thành a dòng, a nhập từ bàn phím)
4. read each column, top to buttom from left to right 
### giải mã 
1. rearrange it into 4 rows, but inserts the letter vertically 
ý tưởng 
đo độ dài của chuỗi l --> chia cho a lấy phần nguyên --> nếu có dư thì a[i][l/a+1] i chạy từ a-1 đến a-1-phần dư --> in ra theo hàng dọc 