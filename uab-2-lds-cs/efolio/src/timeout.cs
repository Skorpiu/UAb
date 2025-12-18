try { 
  if (cliente.timeout)
   throw new ApplicationException("Connection Timeout.");
  else
   cliente.session.SendMsg(new NetMsg {text = ipt});
} 
catch (Exception e)
{
	Console.WriteLine(w)
}