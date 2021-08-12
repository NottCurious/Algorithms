from time import sleep

nums = [20]

for num in nums:
    while num != 1:
        if num % 2 == 0:
            num /= 2
        else:
            num = (3 * num + 1)

        print('Num: {}'.format(num), end='\r')
        sleep(0.0625)
    