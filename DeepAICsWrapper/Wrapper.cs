using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;
using DeepAI;

namespace DeepAICsWrapper
{
    public static class Wrapper
    {
      public static string Densecap_ProcessFile(string key, string filename) 
      {
        Trace.WriteLine("Densecap_ProcessFile");
        Trace.WriteLine(key + ";");
        Trace.WriteLine(filename + ";");
        DeepAI_API api = new DeepAI_API(apiKey: key);
        Debug.WriteLine("Densecap_ProcessFile 1");
        StandardApiResponse resp = api.callStandardApi("densecap", new
        {
          image = File.OpenRead(filename),
        });
      Trace.WriteLine("Densecap_ProcessFile 2");
        return api.objectAsJsonString(resp);
      }
    }
}
