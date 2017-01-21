---
title: "Segregation Problem"
permalink: /QE/SP
excerpt: "A model simulation and prediction of segregation."
modified: 2017-01-21 22:36:11
---

Question：Suppose there are A = 500 people live in the same area. Half of them are green people and half are yellow people. They will be unhappy if the number of different-color people living closest to them is above B = 7. Will the distribution of them be segregation or not.

Key part : decided those unhappy ones and give them a random position.

Flaws : we don't take in consideration that people won't move to a different-colored area if his motive is to stay with the same-colored people.

```python
%matplotlib inline
```


```python
import matplotlib.pyplot as plt
import random
import numpy as np

# 1~green 0~orange
random.seed(10) # for reproduciblity

class agent():
    
    def __init__(self,type):
        self.type = type
        self.location = (random.uniform(0,1),random.uniform(0,1))
    
    def judge(self): # decided happy or not
        self.number = 0
        self.distance = []
        for agent in agents:
            if self != agent:
                self.distance.append((self.get_distance(agent),agent))
        self.distance.sort()
        for i in range(neighbor_num):
            if self.distance[i][1].type == self.type:
                self.number+=1
        return self.number  >= happy_num
    
    def get_distance(self,other): 
        "calculate the euclidean distance between instances"
        return ((self.location[0]-other.location[0])**2 + (self.location[1]-other.location[1])**2)**0.5
    
    def revolution(self):
    "set a random position"
        self.location = (random.uniform(0,1),random.uniform(0,1))

def plot(agents):
    x_green,y_green,x_orange,y_orange = [],[],[],[]
    for agent in agents:
        if agent.type == 1:
            x_green.append(agent.location[0])
            y_green.append(agent.location[1])
        else :
            x_orange.append(agent.location[0])
            y_orange.append(agent.location[1])
    fig, ax = plt.subplots(figsize=(8, 8))
    plot_args = {'markersize' : 8, 'alpha' : 0.6}
    ax.set_axis_bgcolor('azure')
    ax.plot(x_green, y_green, 'o', markerfacecolor='orange',  **plot_args)
    ax.plot(x_orange, y_orange, 'o', markerfacecolor='green', **plot_args)
    ax.set_title('Cycle {}'.format(count-1))
    plt.show()


    
## some values
happy_num = 7
sample_num = 250
neighbor_num =10


## Main
agents = []
for i in range(sample_num):
    agents.append(agent(0))
    agents.append(agent(1))
count = 1
while(1):
    no_one_move = True
    plot(agents)
    count+=1
    for agent in agents:
        if agent.judge() == 0: 
            # if someone is unhappy, set a new position
            agent.revolution()
            no_one_move = False
    if no_one_move == True:
        print('Converged')
        break
```


![Cycle0](https://towardsyou.github.io/images/output_2_0.png)



![Cycle1](https://towardsyou.github.io/images/output_2_1.png)



      ······



![Cycle13](https://towardsyou.github.io/images/output_2_13.png)


    Converged