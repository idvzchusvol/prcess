set nocp
call plug#begin()
Plug 'tpope/vim-sensible'
Plug 'godlygeek/tabular'
Plug 'mhinz/vim-startify'
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'jiangmiao/auto-pairs'
Plug 'itchyny/lightline.vim'
Plug 'morhetz/gruvbox'
call plug#end()
set nu
set ai
set smartindent
set cindent
set cursorline
set wildmenu
set laststatus=2
set showcmd
set noswapfile
set mouse=a
set termguicolors
set noshowmode
set ts=4
set sw=4
set sts=4
set et
compiler gcc
set makeprg=g++\ %\ -o\ %<\ -Wall
let g:lightline = {'colorscheme': 'gruvbox'}
colorscheme gruvbox
inoremap <C-x> <C-o>:w<CR>
nnoremap <Leader> :make<CR>
