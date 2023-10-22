set nocompatible            " disable compatibility to old-time vi
set hlsearch                " highlight search 
set incsearch               " incremental search
set tabstop=4               " number of columns occupied by a tab 
set softtabstop=4           " see multiple spaces as tabstops so <BS> does the right thing
set expandtab               " converts tabs to white space
set shiftwidth=4            " width for autoindents
set autoindent              " indent a new line the same amount as the line just typed
set number                  " add line numbers
set wildmode=longest,list   " get bash-like tab completions
set cc=80                  " set an 80 column border for good coding style
syntax on                   " syntax highlighting
set mouse=a                 " enable mouse click
set clipboard=unnamedplus   " using system clipboard
set cursorline              " highlight current cursorline
set cursorcolumn
set ttyfast                 " Speed up scrolling in Vim
" set spell                 " enable spell check (may need to download language package)
" set noswapfile            " disable creating swap file
" set backupdir=~/.cache/vim " Directory to store backup files.

set nobackup
set scrolloff=10
set nowrap
set showcmd
set showmode
set showmatch

filetype plugin indent on   "allow auto-indenting depending on file type
filetype plugin on

autocmd filetype cpp nnoremap <F5> :w <CR> :!g++ -std=c++14 -O2 -Wall % -o %:r && ./%:r<CR>
autocmd filetype cpp nnoremap cpf i#include <bits/stdc++.h><Esc>ousing namespace std;<Esc>o<Esc>o#define debug(x) cerr << #x << " is " << x << endl<Esc>otypedef long long ll;<Esc>otypedef pair<int, int> P;<Esc>oconst int INF = 0x3f3f3f3f;<Esc>o<CR>int main()<Esc>o{<Esc>oios::sync_with_stdio(false);<Esc>ocin.tie(0);<Esc>o<CR>return 0;<Esc>o}<Esc>kki

call plug#begin("~/.vim/plugged")

 Plug 'honza/vim-snippets'
 Plug 'scrooloose/nerdtree'
 Plug 'vim-airline/vim-airline'      " lean & mean status/tabline for vim that's light as air
 Plug 'instant-markdown/vim-instant-markdown', {'for': 'markdown', 'do': 'yarn install'}
 Plug 'github/copilot.vim'

call plug#end()

nnoremap <F2> :NERDTreeToggle<CR>
nnoremap <C-n> :NERDTreeFocus<CR>
let NERDTreeWinPos="right"
