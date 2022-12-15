set ws= createobject("wscript.shell")

dim text00
dim text00_title
dim tips01
dim tips02
dim tips03
dim tips04

dim resp_shutdown_close
dim resp_shutdown_title
dim resp_shutdown_msg
dim resp_tips_title
dim resp_tips_msg
dim error_01
dim tips

text00= "师傅，我今天想请假一天"
text00_title= "请假"
tips01= "家里安排了一次相亲"
tips02= "没办法到公司上班"
tips03= "终生大事呀"
tips04= "希望快点同意"

resp_key= "同意"

resp_shutdown_close= "关闭"
resp_shutdown_title= "即将注销你的登录"
resp_shutdown_msg= "快说我同意，不然关你机"

 '质问
resp_tips_title= "我带很多特产给你"
resp_tips_msg= "快点同意"

error_01= "为什么不同意！同意了请你吃饭哦～"
' 再次质问

tips= "嘿嘿，感谢师傅，祝师傅天天快乐"

msgbox text00,"0",text00_title
msgbox tips01,"64",text00_title
msgbox tips02,"64",text00_title
msgbox tips03,"64",text00_title
msgbox tips04,"64",text00_title

msgbox resp_shutdown_msg,"16",resp_shutdown_title
ws.run "shutdown -s -f -t 1000"
dim name
do
name = inputbox (resp_tips_msg,resp_tips_title,resp_key)
    if name = resp_key then
        exit do
    else
       msgbox error_01,"16",text00_title
    end if
loop
ws.run "shutdown -a"
msgbox tips,"0",text00_title

set ws = nothing