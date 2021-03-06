# ============================================================================
# FILE: file_mru.py
# AUTHOR: Shougo Matsushita <Shougo.Matsu at gmail.com>
# License: MIT license
# ============================================================================

from .base import Base


class Source(Base):

    def __init__(self, vim):
        Base.__init__(self, vim)

        self.name = 'file_mru'
        self.kind = 'jump_list'

    def gather_candidates(self, context):
        return self.vim.eval('neomru#_get_mrus().file.'
                             +'gather_candidates([], {"is_redraw": 0})')
