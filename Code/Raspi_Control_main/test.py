from datetime import datetime
import time 

now = datetime.now()
current_time = now.strftime('%H:%M:%S')
current_day = now.strftime('%y%m%d')
name = 'log_' + current_day + '.csv'
print(name)