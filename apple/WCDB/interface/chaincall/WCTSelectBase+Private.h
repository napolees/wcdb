/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>
#import <WCDB/WCTSelectBase.h>
#import <WCDB/statement_recyclable.hpp>

@interface WCTSelectBase () {
@protected
    BOOL _prepared;
    WCDB::RecyclableStatement _statementHandle;
    WCDB::StatementSelect _statement;
}

- (BOOL)lazyPrepare;
- (BOOL)extractPropertyToObject:(WCTObject *)object
                        atIndex:(int)index
              withColumnBinding:(const std::shared_ptr<WCTColumnBinding> &)columnBinding;
- (id /* WCTValue* */)extractValueAtIndex:(int)i;

@end