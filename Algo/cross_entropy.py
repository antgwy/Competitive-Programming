import torch
import torch.nn.functional as F

# 二元, torch.rand [0, 1) 均匀分布，torch.randn (0, 1) 正态分布
p = torch.rand((10, 1))
y = torch.randint(0, 2, size=(10, 1)).to(torch.float)

def cross_entropy(p: torch.tensor, y: torch.tensor):
    eps = 1e-6
    return -torch.sum(y * torch.log(p + eps) + (1 - y) * torch.log(1 - p + eps)) / len(y)
    
print(cross_entropy(p, y))
print(F.binary_cross_entropy(p, y))

# 多元
p = torch.randn((10, 3))
y = torch.randint(3, (10, ), dtype=torch.int64)

def mul_cross_entropy(p, y):
    p = F.softmax(p, dim=1)
    return -torch.sum(F.one_hot(y) * torch.log(p + 1e-6)) / y.shape[0]
    
print(mul_cross_entropy(p, y))
print(F.cross_entropy(p, y))  