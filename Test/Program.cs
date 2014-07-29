using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVM;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            var context = new LLVMContext();
            var module = new Module("NoName", context);
            var builder = new IRBuilder(context);
            var t = builder.getInt32Ty();
            var funcType = FunctionType.get(t, false);
            var main = Function.Create(funcType, GlobalValue.LinkageTypes.ExternalLinkage, "main", module);
            var entry = BasicBlock.Create(context, "entrypoint", main);
            builder.SetInsertPoint(entry);

            var hello = builder.CreateGlobalStringPtr("Hello, World!");

            var putsType = FunctionType.get(builder.getInt32Ty(),
                new[] { builder.getInt8Ty().getPointerTo(0) }, false);
            var putsFunc = module.getOrInsertFunction("puts", putsType);

            builder.CreateCall(putsFunc, hello);

            var variable = builder.CreateAlloca(t);
            var val = ConstantInt.get(t, 127);
            builder.CreateStore(val, variable);

            builder.CreateRetVoid();

            var pm = new PassManager();

            module.dump();

            Console.ReadKey();
        }
    }
}
