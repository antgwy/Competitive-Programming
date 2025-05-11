import torch
import torch.nn.functional as F
from einops import rearrange

torch.manual_seed(42)

# class SelfAttn(torch.nn.Module):
#     def __init__(self, dim, num_heads):
#         super().__init__()
        
#         self.dim = dim
#         self.num_heads = num_heads
        
#         self.w_q = torch.nn.Linear(dim, dim)
#         self.w_k = torch.nn.Linear(dim, dim)
#         self.w_v = torch.nn.Linear(dim, dim)
        
#     def forward(self, x):
#         bs, seqlen, dim = x.size()
        
#         q = self.w_q(x).view(bs, seqlen, num_heads, dim // self.num_heads).transpose(1, 2)
#         k = self.w_k(x).view(bs, seqlen, num_heads, dim // self.num_heads).transpose(1, 2)
#         v = self.w_v(x).view(bs, seqlen, num_heads, dim // self.num_heads).transpose(1, 2)
        
#         att = F.softmax(torch.matmul(q, k.transpose(-2, -1)) / (dim // self.num_heads) ** 0.5, dim=-1)
        
#         out = torch.matmul(att, v).transpose(1, 2).contiguous().view(bs, seqlen, dim)
        
#         return out


class SelfAttn(torch.nn.Module):
    def __init__(self, dim, num_heads):
        super().__init__()
        self.dim = dim
        self.num_heads = num_heads
        self.head_dim = dim // num_heads
        self.scale = self.head_dim ** -0.5

        self.to_q = torch.nn.Linear(dim, dim)
        self.to_k = torch.nn.Linear(dim, dim)
        self.to_v = torch.nn.Linear(dim, dim)
 
    def forward(self, x): # x: [batch, seqlen, dim]
        q = self.to_q(x)
        k = self.to_k(x)
        v = self.to_v(x)
        
        q, k, v = map(lambda t: rearrange(t, "b n (h d) -> (b h) n d", h=self.num_heads), (q, k, v))

        sim = torch.einsum("b i d, b j d -> b i j", q, k) * self.scale
        attn = F.softmax(sim, dim=-1)
        out = torch.einsum("b i j, b j d -> b i d", attn, v)
        out = rearrange(out, "(b h) n d -> b n (h d)", h=self.num_heads)
        
        return out

if __name__ == "__main__":
    batch_size = 2
    seqlen = 4
    dim = 16    
    num_heads = 4

    attn = SelfAttn(dim, num_heads)

    x = torch.randn(batch_size, seqlen, dim)
    output = attn(x)

    print(f"x.shape: {x.shape}\nx: {x}")
    print(f"output.shape: {output.shape}\noutput: {output}")