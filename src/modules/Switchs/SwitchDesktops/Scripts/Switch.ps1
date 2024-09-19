
# 导入模块
# Import-Module VirtualDesktop
# Install-Module -Name VirtualDesktop -Scope CurrentUser
# Get-Command -Module VirtualDesktop

# 切换到第一个虚拟桌面
#Switch-VirtualDesktop  1


param (
    [int]$d
)

Switch-Desktop 1

return 'hello'