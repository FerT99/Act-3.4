g++ main.cpp -o app
mkdir results
for i in 0 1 2 3 4
do
    ./app input$i.txt ./results/myoutput$i.txt
    diff output$i.txt ./results/myoutput$i.txt
done